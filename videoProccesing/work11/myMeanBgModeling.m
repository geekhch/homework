v = VideoReader('inputVideo.avi');
o = VideoWriter('outputVideo.avi');


open(o);
last  = double(rgb2gray(readFrame(v)));
count = 1;
timecount = 0;
while hasFrame(v)
    tic
    f =double(rgb2gray(readFrame(v)));
    diff = f-last;
    diff = (diff-min(min(diff)));
    diff = single(diff*255/max(max(diff))>80);
%         currAxes = axes;
%         imshow(diff, 'Parent', currAxes);
%         currAxes.Visible = 'off';
    last = last*(count/(count+1))+f*(1/(1+count)); %重新计算前count+1帧的均值
    count = count+1;
    timecount = timecount + toc;
    writeVideo(o,diff);
end
close(o);
disp('success');
disp(timecount)