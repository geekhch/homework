clear all
close all
clc

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Demo for Motion Estimation
% version 1.6
%
% Stanley Chan
% 
% Copyright 2010
% University of California, San Diego
%
% Last modified: 
% 29 Apr, 2010
% 29 Jun, 2010
%  7 Jul, 2010
%  3 Jan, 2013 clean up demo
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% Parameters
opts.BlockSize   = 8;
opts.SearchLimit = 10;

% Read image
img0 = im2double(imread('imgs/city001.png'));
img1 = im2double(imread('imgs/city002.png'));

% Motion estimation
tic
[MVx, MVy] = Forward_ME(img1, img0, opts);
toc

% Motion Compensation
tic
imgMC = reconstruct(img1, MVx, MVy);
toc

% Evaluation
[M N C] = size(imgMC);
Res  = imgMC-img0(1:M, 1:N, 1:C);
MSE  = norm(Res(:), 'fro')^2/numel(imgMC);
PSNR = 10*log10(max(imgMC(:))^2/MSE);

% Show results
figure(1);
quiver(MVx(end:-1:1,:), MVy(end:-1:1,:));
title('Motion Vector Field');

figure(2);
subplot(221);
imshow(img0); title('img_0');

subplot(222);
imshow(img1); title('img_1');

subplot(223);
imshow(imgMC); title('img_M');

subplot(224); 
T = sprintf('img_M - img_1, PSNR %3g dB', PSNR);
imshow(rgb2gray(imgMC)-rgb2gray(img1(1:M, 1:N, :)), []); title(T);
