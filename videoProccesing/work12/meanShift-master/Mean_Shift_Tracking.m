%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% MEAN SHIFT TRACKING
% ----------------------
% YOU HAVE TO MODIFY THIS FILE TO MAKE IT RUN!
% YOU CAN ADD ANY FUNCTION YOU FIND USEFUL!
% In particular, you have to create the different functions:
%	- cd = color_distribution(imagePatch, m)
%	- k = compute_bhattacharyya_coefficient(p,q)
%	- weights = compute_weights(imPatch, qTarget, pCurrent, Nbins)
% 	- z = compute_meanshift_vector(imPatch, prev_center, weights)
%
% the function to extract an image part is given.
% ----------------
% Authors: D. SIdib锟?
% Date: October 19th, 2011
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

clc
clear all
close all

%% read images
imPath = '.\Dog\img'; imExt = 'jpg';

%%%%% LOAD THE IMAGES
%=======================
% check if directory and files exist
if isdir(imPath) == 0
    error('USER ERROR : The image directory does not exist');
end

filearray = dir([imPath filesep '*.' imExt]); % get all files in the directory
NumImages = size(filearray,1); % get the number of images
if NumImages < 0
    error('No image in the directory');
end

disp('Loading image files from the video sequence, please be patient...');
% Get image parameters
imgname = [imPath filesep filearray(1).name]; % get image name
I = imread(imgname);
VIDEO_WIDTH = size(I,2);
VIDEO_HEIGHT = size(I,1);

ImSeq = zeros(VIDEO_HEIGHT, VIDEO_WIDTH, NumImages);
for i=1:NumImages
    imgname = [imPath filesep filearray(i).name]; % get image name
    ImSeq(:,:,i) = rgb2gray(imread(imgname)); % load image
end
disp(' ... OK!');

%% 

%%%%% INITIALIZE THE TRACKER
%=======================

% HERE YOU HAVE TO INITIALIZE YOUR TRACKER WITH THE POSITION OF THE OBJECT IN THE FIRST FRAME

% You can use Background subtraction or a manual initialization!
% For manual initialization use the function imcrop
bbox = load('.\Dog\groundtruth_rect.txt'); 
%[patch, rect] = imcrop(ImSeq(:,:,1)./255);
rect = bbox(1,:);
% DEFINE A BOUNDING BOX AROUND THE OBTAINED REGION : this gives the initial state

% Get ROI Parameters
ROI_Center = round([rect(1)+rect(3)/2 , rect(2)+rect(4)/2]); 
ROI_Width = rect(3);
ROI_Height = rect(4);

% you can draw the bounding box and show it on the image
% rectangle('Position', rect, 'EdgeColor','k','FaceColor',[0 .5 .5]);

%% MEANSHIFT TRACKING
%=======================

%% FIRST, YOU NEED TO DEFINE THE COLOR MODEL OF THE OBJECT

% compute target object color probability distribution given the center and size of the ROI
imPatch = extract_image_patch_center_size(ImSeq(:,:,1), ROI_Center, ROI_Width, ROI_Height);

% color distribution in RGB color space
Nbins = 8;
TargetModel = color_distribution(imPatch, Nbins);

% Mean-Shift Algorithm 
figure('name', 'Mean Shift Algorithm', 'units', 'normalized', 'outerposition', [0 0 1 1]);
prev_center = ROI_Center;
disp(prev_center);
dist = zeros(NumImages, 1); 
dist(1) = 0; 
errors = zeros(NumImages);
for n = 2:NumImages
    ground_rect = bbox(n,:);
    ground_truth_center = round([ground_rect(1)+ground_rect(3)/2 , ground_rect(2)+ground_rect(4)/2]);
    % get next frame
    I = ImSeq(:,:,n);
    while(1)        
    	% STEP 1
    	% calculate the pdf of the previous position
    	imPatch = extract_image_patch_center_size(I, prev_center, ROI_Width, ROI_Height);
    	ColorModel = color_distribution(imPatch, Nbins);
    	% evaluate the Bhattacharyya coefficient
     	rho = compute_bhattacharyya_coefficient(TargetModel, ColorModel);
    
    	% STEP 2, 3
    	% derive the weights
    	weights = compute_weights_NG(imPatch, TargetModel, ColorModel, Nbins);
    	% compute the mean-shift vector
    	% using Epanechnikov kernel, it reduces to a weighted average
        z = compute_meanshift_vector(imPatch, prev_center, weights);
    	new_center = round(z);
        
        % STEP 4, 5
        imPatch2 = extract_image_patch_center_size(I, new_center, ROI_Width, ROI_Height);
    	ColorModel2 = color_distribution(imPatch2, Nbins);
    	% evaluate the Bhattacharyya coefficient
     	rho2 = compute_bhattacharyya_coefficient(TargetModel, ColorModel2);
        while(rho2<rho)
            new_center = (prev_center+new_center)/2;
            
            imPatch2 = extract_image_patch_center_size(I, new_center, ROI_Width, ROI_Height);
            ColorModel2 = color_distribution(imPatch2, Nbins);
            % evaluate the Bhattacharyya coefficient
            rho2 = compute_bhattacharyya_coefficient(TargetModel, ColorModel2);
        end

        % STEP 6
        if norm(new_center-prev_center, 1) < 0.0001
            break
        end
        prev_center = new_center;
        
    end
    
    disp(new_center);
    errors(n) = sumsqr(ground_truth_center-new_center);  %中心点残差平方和
    subplot(1,1,1); imshow(I, []);
    hold on;
	plot(new_center(1), new_center(2) , '+', 'Color', 'r', 'MarkerSize',10);
    drawnow;
	
end
figure;
plot(errors);
title('error(sumsqr of reidual error)');
saveas(gcf,'error','png');