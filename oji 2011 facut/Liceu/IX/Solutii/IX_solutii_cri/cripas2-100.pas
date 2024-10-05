{prof. Zoltan Szabo - solutie problema cri - implementare fara tablouri}

const maxim=100000000;
var f,g:text;
    z,n,m,x,y,i,j:integer;
    p,min1,min2,min3,min4,s1,s2,s3,s4,t,k:longint;
begin
  assign(f,'cri.in');
  reset(f);
  assign(g,'cri.out');
  rewrite(g);
  readln(f,n,m,x,y);
  
  s1:=0;s2:=0;s3:=0;s4:=0;
  min1:=maxim;min2:=maxim;min3:=maxim;min4:=maxim;
  for i:=1 to n do
    for j:=1 to m do
    begin
      read(f,p);
      if (i<=x) and (j<=y) then
        begin
          s1:=s1+p;
          if odd(i+j) and (p<min1) then min1:=p;
        end;
      if (i<=x) and (j>=y) then
        begin
          s2:=s2+p;
          if odd(i+j+1+m) and (p<min2) then min2:=p;
        end;
      if (i>=x) and (j<=y) then
        begin
          s3:=s3+p;
          if odd(i+j+1+n) and (p<min3) then min3:=p;
        end;
      if (i>=x) and (j>=y) then
        begin
          s4:=s4+p;
          if odd(i+j+m+n) and (p<min4) then min4:=p;
        end;
    end;
  if odd(x) or odd(y) then
    begin
      z:=1;
      t:=s1;
      k:=x*y;
    end
  else
    begin
      z:=1;
      t:=s1-min1;
      k:=x*y-1;
    end;
  if odd(x) or odd(m-y+1) then
    begin
      if (s2>t) or ((s2=t) and (k>x*(m-y+1))) then
        begin
          z:=2;
          t:=s2;
          k:=x*(m-y+1);
        end
    end
  else
    begin
      if (s2-min2>t) or ((s2-min2=t) and (k>x*(m-y+1)-1)) then
        begin
          z:=2;
          t:=s2-min2;
          k:=x*(m-y+1)-1;
        end
    end;
  if odd(n-x+1) or odd(y) then
    begin
      if (s3>t) or ((s3=t) and (k>(n-x+1)*y)) then
        begin
          z:=3;
          t:=s3;
          k:=(n-x+1)*y;
        end
    end
  else
    begin
      if (s3-min3>t) or ((s3-min3=t) and (k>(n-x+1)*y-1)) then
        begin
          z:=3;
          t:=s3-min3;
          k:=(n-x+1)*y-1;
        end
    end;
  if odd(n-x+1) or odd(m-y+1) then
    begin
      if (s4>t) or ((s4=t) and (k>(n-x+1)*(m-y+1))) then
        begin
          z:=4;
          t:=s4;
          k:=(n-x+1)*(m-y+1);
        end
    end
  else
    begin
      if (s4-min4>t) or ((s4-min4=t) and (k>(n-x+1)*(m-y+1)-1)) then
        begin
          z:=4;
          t:=s4-min4;
          k:=(n-x+1)*(m-y+1)-1;
        end
    end;

  writeln(g,z,' ',t,' ',k);
  close(f);
  close(g);
end.