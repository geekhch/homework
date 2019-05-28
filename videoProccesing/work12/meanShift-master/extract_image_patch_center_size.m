function imPatch = extract_image_patch_center_size(I, c, w, h)
% This function extract an image patch in image I given the center and size of the ROI

VIDEO_WIDTH = size(I,2);
VIDEO_HEIGHT = size(I,1);

y = c(2)-h/2;
x = c(1)-w/2;

r2 = round(min(VIDEO_HEIGHT, y+h+1));
c2 = round(min(VIDEO_WIDTH, x+w+1));
r = round(max(y, 1));
c = round(max(x, 1));
imPatch = I(r:r2, c:c2, :);
end