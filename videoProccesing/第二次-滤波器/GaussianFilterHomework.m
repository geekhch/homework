
function [ ] = GaussianFilterHomework(path, sigma, s)
    % 
    img = imread(path);
    imshow(img)
    R= img(:,:,1);
    G = img(:,:,2);
    B = img(:,:,3);
    R = gff(R,sigma, s);
    G = gff(G,sigma, s);
    B = gff(B,sigma, s);
    ret = cat(3,R,G,B);
    figure
    imshow(ret);
end

function [ ret ] = gff( gray_img, sigma, s)
%GF ¸ßË¹ÂË²¨
    [X,Y] = meshgrid(1:1:s,1:1:s);
    X = X-(s+1)/2;
    Y = Y-(s+1)/2;
    D = exp(-(X.*X+Y.*Y)./(2*sigma^2));
    D = D/sum(D);
    ret = imfilter(gray_img, D);
end


