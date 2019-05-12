clear;clc;
view = imread('view1.png');
disp = double(imread('disp1.png'));
[r,c] = size(disp);

% �������
f=3740;  % fx=fy=f
d_min = 200;
disp = disp+d_min;


% �����ж���δ�ڵ���
index= 0;
for yl=1:r
    for xl=1:c
        if disp(yl,xl)>200
            index = index +1;
        end
    end
end

% ��������������ɫ
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

% ģ�ͻ����뱣��
model = pointCloud(xyz,'Color',color);
pcshow(model);
pcwrite(model, 'model.ply');