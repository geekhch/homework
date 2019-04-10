originalImage = im2double(imread('girl.jpg')); 
% h1 = fspecial('gaussian', 7, 2); 
h1 = [1 1 1; 1 -8 1; 1 1 1]; 
filteredImage = imfilter(originalImage, h1); 
sharpenedImg = originalImage - filteredImage; 
figure; 
subplot(1,3,1); imshow(originalImage); title('Original Image'); 
subplot(1,3,2); imshow(filteredImage); title('Filtered Image'); 
subplot(1,3,3); imshow(sharpenedImg); title('Sharpened Image'); 