
function [ ] = ColorFilterHomework(path, sigma, s)
    % 
    img = imread(path);
    imshow(img)
    R= img(:,:,1);
    G = img(:,:,2);
    B = img(:,:,3);
    R = colorfilterHelper(img,sigma, s);
%     G = colorfilterHelper(G,sigma, s);
%     B = colorfilterHelper(B,sigma, s);
%     ret = cat(3,R,G,B);
    figure
    imshow(R);
end

function [ b ] = colorfilterHelper( A, sigma, s )
    a = double(padarray(A,[(s-1)/2,(s-1)/2,0],'replicate', 'both'));
    [h,w,d] = size(A); 
    b = zeros(h,w,3);
    centerPad = zeros(s,s,3);
    
    % 遍历所有像素
    for i=1:h
        for j = 1:w
            raw = a(i:i+s-1,j:j+s-1,:);
            
            center = raw((s+1)/2, (s+1)/2,:);
            % 中心像素点扩展为与filter相同大小向量
            for k=1:s
                for p=1:s
                    centerPad(k,p,:) = center; 
                end
            end
            % 求颜色滤波的filter
            f = sqrt(sum((raw-centerPad).^2,3))/(2*sigma^2);
            f = exp(-1*f);
            f = f/sum(sum(f));
            
            %对三个通道分别进行滤波
            b(i,j,1) = sum(sum(f.*a(i:i+s-1,j:j+s-1,1)));
            b(i,j,2) = sum(sum(f.*a(i:i+s-1,j:j+s-1,2)));
            b(i,j,3) = sum(sum(f.*a(i:i+s-1,j:j+s-1,3)));
        end
    end
    b = uint8(b);
end

