for i = 1:MaxX
        for j = 1 : MaxY
            if M(i,j) == color
                rectangle('Curvature',[1,1],'Position',[i-1,j-1,1,1],'FaceColor','blue');
            else
                if M(i,j) == color2
                    rectangle('Curvature',[1,1],'Position',[i-1,j-1,1,1],'FaceColor','red');
                end
            end
        end
end   
