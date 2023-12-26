dx=abs(X2-X1); dy=abs(Y2-Y1);
sy=0;
sx=0;
reverse=0;
if X2<X1 
     sx=true; 
else 
    sx=false; 
end
if Y2<Y1 
     sy=true; 
else 
    sy=false; 
end
if dx<dy 
    reverse=true;
    x=dx; 
    dx=dy; 
    dy=x;  
else 
    reverse=false; 
end
if sym(dx)==0 
     M(X1,Y1)=color4; 
end

slope=dy/dx;
counter=0;
while counter<=dx 
    x=counter;
    y=floor(slope*x+0.5);
    if reverse
        z=x;
        x=y;
        y=z; 
    end;
    if sx 
         x=-x; 
    end
    if sy 
         y=-y; 
    end
	
    rx=x+X1;
    ry=y+Y1;		 
    SidePoints;
     
   counter=counter+1;
end
