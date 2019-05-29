% img = imread('test.jpg');
% % imshow(img);
% haze = rgb2gray(img);
% J_dark = ordfilt2(min(img,[],3),1,ones(3,3)); %最小值滤波
img_name='test.jpg';

% 原始图像

I=im2double(imread(img_name));

% 获取图像大小

[h,w,c]=size(I);

win_size = 7;

img_size=w*h;

dehaze=I;


figure, imshow(I);


win_dark=ordfilt2(min(I,[],3),1,ones(win_size,win_size));

 

figure, imshow(win_dark);

%输出darkchannel图像

%%%%%%%%%%%%%%% 


win_b=1-win_dark;


%%%%%%%%%%%%%%%

 %选定精确dark value坐标
% win_b = zeros(img_size,1);
% 
%  
% 
% %rem函数为求余函数，有可能是进行边缘处理
% 
% for ci=1:h
% 
%     for cj=1:w
% 
%         if(rem(ci-8,15)<1)
% 
%             if(rem(cj-8,15)<1)
% 
%                 win_b(ci*w+cj)=win_dark(ci*w+cj);
% 
%             end
% 
%         end
% 
%       
% 
%     end
% 
% end

 

%显示分块darkchannel

%figure, imshow(win_dark);

 

neb_size = 9;

win_size = 1;

epsilon = 0.0000001;

%指定矩阵形状

indsM=reshape([1:img_size],h,w);

%是不是win_dark

%计算矩阵L

tlen = img_size*neb_size^2;

row_inds=zeros(tlen ,1);

col_inds=zeros(tlen,1);

vals=zeros(tlen,1);

len=0;

for j=1+win_size:w-win_size

    for i=win_size+1:h-win_size

        if(rem(ci-8,15)<1)

            if(rem(cj-8,15)<1)

                continue;

            end

        end

      win_inds=indsM(i-win_size:i+win_size,j-win_size:j+win_size);

      win_inds=win_inds(:);%列显示

      winI=I(i-win_size:i+win_size,j-win_size:j+win_size,:);

      winI=reshape(winI,neb_size,c); %三个通道被拉平成为一个二维矩阵 3*9

      win_mu=mean(winI,1)';  %求每一列的均值 如果第二个参数为2 则为求每一行的均值  //矩阵变向量

      win_var=inv(winI'*winI/neb_size-win_mu*win_mu' +epsilon/neb_size*eye(c)); %求方差

 

      winI=winI-repmat(win_mu',neb_size,1);%求离差

      tvals=(1+winI*win_var*winI')/neb_size;% 求论文所指的矩阵L

 

      row_inds(1+len:neb_size^2+len)=reshape(repmat(win_inds,1,neb_size),neb_size^2,1);

      col_inds(1+len:neb_size^2+len)=reshape(repmat(win_inds',neb_size,1),neb_size^2,1);

      vals(1+len:neb_size^2+len)=tvals(:);

      len=len+neb_size^2;

    end

end

vals=vals(1:len);

row_inds=row_inds(1:len);

col_inds=col_inds(1:len);

%创建稀疏矩阵

A=sparse(row_inds,col_inds,vals,img_size,img_size);

%求行的总和 sumA为列向量

sumA=sum(A,2);

%spdiags(sumA(:),0,img_size,img_size) 创建img_size大小的稀疏矩阵其元素是sumA中的列元素放在由0指定的对角线位置上。

A=spdiags(sumA(:),0,img_size,img_size)-A;

 

 

  %创建稀疏矩阵

  D=spdiags(win_b(:),0,img_size,img_size);

  lambda=1;

  x=(A+lambda*D)\(lambda*win_b(:).*win_b(:));   %求解式15

 

   %去掉0-1范围以外的数

  alpha=max(min(reshape(x,h,w),1),0);

figure, imshow(alpha);

A=220/255; %大气光没有去计算

%去雾

for i=1:c

    for j=1:h

        for l=1:w

            dehaze(j,l,i)=(I(j,l,i)-A)/alpha(j,l)+A;

        end

    end

end

figure, imshow(dehaze);