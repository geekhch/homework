function [output] = nlm(input, search_wsize, similarity_wsize, sigma)
 
 %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
 %
 %  input: image to be filtered
 %  search_wsize: radio of search window
 %  similarity_wsize: radio of similarity window
 %  sigma: degree of filtering
 %
 %  Author: Jose Vicente Manjon Herrera & Antoni Buades
 %  Date: 09-03-2006
 %
 %  Implementation of the Non local filter proposed for A. Buades, B. Coll and J.M. Morel in
 %  "A non-local algorithm for image denoising"
 %
 %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

 % Size of the image
 [rows, cols] = size(input); 
 % Memory for the output
 output = zeros(rows,cols);
 % Replicate the boundaries of the input image
 input2 = padarray(input, [similarity_wsize similarity_wsize], 'symmetric');
 
 % distance kernel / weight
 kernel = make_kernel(similarity_wsize); % (2*similarity_wsize+1)*(2*similarity_wsize+1)
 kernel = kernel / sum(sum(kernel)); % normalization 
 
 sigma = sigma*sigma;
 % for each pixel (i, j)
 for i = 1 : rows 
    for j = 1 : cols
        
         % location of (i, j) in input2 is (i1, j1)
         i1 = i+ similarity_wsize;
         j1 = j+ similarity_wsize;
         % extract the patch centered at (i1, j1)
         W1= input2(i1-similarity_wsize : i1+similarity_wsize , j1-similarity_wsize : j1+similarity_wsize);
         
         wmax=0; 
         average=0;
         sweight=0;
         
         % boundary of the search window 
         rmin = max(i1-search_wsize, similarity_wsize+1);
         rmax = min(i1+search_wsize, rows+similarity_wsize);
         smin = max(j1-search_wsize, similarity_wsize+1);
         smax = min(j1+search_wsize, cols+similarity_wsize);
         
         for r = rmin : 1 : rmax % row of the search window
            for s = smin : 1 : smax % col of the search window
                                               
                if(r==i1 && s==j1) 
                    continue; 
                end;
                % extract the patch centered at (r, s) 
                W2 = input2(r-similarity_wsize : r+similarity_wsize , s-similarity_wsize : s+similarity_wsize);                
                % distance between W1 and W2 
                d = sum(sum(kernel.*(W1-W2).*(W1-W2)));
                % weight                                
                w = exp(-d/sigma);                 
                % record wmax                  
                if w > wmax                
                    wmax=w;                   
                end
                % record weight sum 
                sweight = sweight + w;
                % record weighted average 
                average = average + w * input2(r, s);                                  
            end 
         end
         
        % weighted average of the center point      
        average = average + wmax * input2(i1,j1);
        sweight = sweight + wmax; 
                   
        if sweight > 0
            output(i,j) = average / sweight;
        else
            output(i,j) = input(i,j);
        end                
    end
 end
 
end 

 
function [kernel] = make_kernel(similarity_wsize)              
    % kernel size 
    kernel = zeros(2*similarity_wsize+1, 2*similarity_wsize+1);   
    for d = 1 : similarity_wsize   % d: absolute distance to center (x or y direction)
        value = 1 / (2*d+1)^2 ;  
        for i = -d : d
            for j = -d : d
                kernel(similarity_wsize+1-i, similarity_wsize+1-j) = ...
                    kernel(similarity_wsize+1-i,similarity_wsize+1-j) + value ;
            end
        end
    end
    kernel = kernel ./ similarity_wsize; % normalization 

end
