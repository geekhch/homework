img1 = imread('ch01_data\bottle.jpg');
img2 = imread('ch01_data\sky.jpg');
newImg = img1;

% °ÙÒ¶´°Í¼±ÈÀıÈÚºÏ
[width,height,channel] = size(img1);
for i=1:width
    alpha = (rem(i,200))/200;
    newImg(i,:,:) = alpha*img1(i,:,:) + (1-alpha)*img2(i,:,:);
end

imshow(newImg)
imwrite(newImg,'output/ex4_merge.jpg')