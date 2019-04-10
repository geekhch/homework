% ��ȡԭʼ��Ƶ
avi = VideoReader('ch01_data\marple13.avi');
frameNum = avi.NumberOfFrames;
rate = avi.FrameRate;

% ����
newAvi = VideoWriter('output/ex3-1_back.avi');
open(newAvi)
for i=frameNum:-1:1
    f = read(avi,i);
    writeVideo(newAvi, f);
end
close(newAvi)

% 2x���
newAvi = VideoWriter('output/ex3-2_faster.avi');
newAvi.FrameRate = rate*2;
open(newAvi)
for i=1:frameNum
    f = read(avi,i);
    writeVideo(newAvi, f);
end
close(newAvi)

% 2x����
newAvi = VideoWriter('output/ex3-3_slower.avi');
newAvi.FrameRate = rate/2;
open(newAvi)
for i=1:frameNum
    f = read(avi,i);
    writeVideo(newAvi, f);
end
close(newAvi)
