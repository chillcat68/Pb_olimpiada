var f,g:text;
    x,y: array[1..250000] of longint;
    i,n,k:longint;
begin
 assign(f,'ordine.in');
 assign(g,'ordine.out');
 reset(f);
 rewrite(g);
 readln(f,n);
 for i:=1 to n do
  read(f,x[i]);
 readln(f,k);
 if k=1 then
  if n mod 2=1 then
  writeln(g,x[(n+1) div 2])
  else writeln(g,x[n])
  else
  begin
   k:=1;
   for i:=1 to (n+1) div 2 do
       begin
        y[k]:=x[i];
        k:=k+2;
       end;
   k:=2;
   for i:=(n+1) div 2+1 to n do
    begin
     y[k]:=x[i];
     k:=k+2;
    end;
    for i:=1 to n do
     write(g,y[i],' ');
   end;
  close(f);
  close(g);
end.
