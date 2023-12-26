
MaxX=100;
MaxY=100;

Ax = axes('Position',[0.1,0.1,0.8,0.8],'XLim',[0,MaxX],'YLim',[0,MaxY]);

M=zeros(MaxX,MaxY);

color = 2;
color2 = 3;


while 1
    
[X,Y]=ginput(2);

X=floor(X);
Y=floor(Y);


X1=(X(1));
X2=(X(2));

Y1=(Y(1));
Y2=(Y(2));

M(X1,Y1)=color;
M(X2,Y2)=color;

DrawMe;
DrawMatrix;

pause(1)

WideMe;
DrawMatrix;

pause(1);


end

