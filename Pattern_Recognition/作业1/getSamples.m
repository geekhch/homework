function [ sample ] = getSamples( n )
    sampleNum = n;
    count=0;
    sample=zeros(sampleNum,1);
    cur = 1;
    while count<sampleNum
        xt1 = Uniform(-100,100);
        xt2 = Uniform(-100,100);
        n = Uniform(0,1000);
        x1 = min([xt1, xt2]);
        xu = max([xt1, xt2]);
        for i=1:n
            sample(cur)=Uniform(x1,xu);
            cur = cur+1;
            if cur>sampleNum
                break
            end
        end
        if cur>sampleNum
                break
        end
    end
end

