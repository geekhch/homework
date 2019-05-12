clear;clc;
view = imread('view1.png');
disp = double(imread('disp1.png'));
[r,c] = size(disp);

% 相机参数
f=3740;  % fx=fy=f
d_min = 200;
disp = disp+d_min;


% 计算有多少未遮挡点
index= 0;
for yl=1:r
    for xl=1:c
        if disp(yl,xl)>200
            index = index +1;
        end
    end
end

% 计算点云坐标和颜色
xyz = zeros(index,3);
color = uint8(zeros(index,3));
index=1;
for yl=1:r
    for xl=1:c
        if disp(yl,xl)>200
            xyz(index,:) = [(disp(yl,xl)/f)*(yl-r/2),(disp(yl,xl)/f)*(xl-c/2),disp(yl,xl)];
            color(index,:) = view(yl,xl,:);
            index = index+1;
        end
    end
end

% 模型绘制与保存
model = pointCloud(xyz,'Color',color);
pcshow(model);
pcwrite(model, 'model.ply');