clc; clear;
load mask
X = imread('desk.jpg');
image(X)
axis square
colormap(pink(255))
title('Original Image: mask')

meth   = 'gbl_mmc_h'; % Method name
option = 'c';         % 'c' stands for compression
[CR,BPP] = wcompress(option,X,'mask.wtc',meth,'BPP',0.5);

option = 'u';  % 'u' stands for uncompression
Xc = wcompress(option,'mask.wtc');
colormap(pink(255))
subplot(1,2,1); image(X);
axis square;
title('Original Image')
subplot(1,2,2); image(Xc);
axis square;
title('Compressed Image')
xlabel({['Compression Ratio: ' num2str(CR,'%1.2f %%')],['BPP: ' num2str(BPP,'%3.2f')]});

