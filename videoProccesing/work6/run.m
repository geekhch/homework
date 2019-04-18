clc;clear;
X = pcread('model.ply');
% pcshow(X)
hold on
t = [0 0 0]';
R = eye(3,3);
% cam = plotCamera('Location',t,'Orientation',R,'Size',50);
fx=100;fy=100;
cx=20;cy=20;
K = [fx 0 cx;0 fy cy;0 0 1];
S = X.Location;
m = K*S';
mx = round(m(1,:)./m(3,:))';
my = round(m(2,:)./m(3,:))';
C = X.Color;
% img = uint8(zeros(100,100,3));

scatter(mx,my,ones(1,53215)*5,im2double(C),'filed')

