{prof. Zoltan Szabo - 100 p}
var v,nr:array[-99999..99999] of longint;
    st,dr,L,i,j,n:longint;
    f,g:text;
    x:char;
    volumL,jumatate,total,ss,sd:int64;
begin
  assign(f,'vase.in');
  reset(f);
  assign(g,'vase.out');
  rewrite(g);
  readln(f,n);
  readln(f,v[0],x,x);
  nr[0]:=1;
  st:=0;dr:=0;
  for i:=2 to n do
    begin
      readln(f,L,x,x);
      if x='S' then
        begin
          st:=st-1;
          v[st]:=L;
          nr[st]:=i;
        end
      else
        begin
          dr:=dr+1;
          v[dr]:=L;
          nr[dr]:=i;
        end;
    end;
  readln(f,L);
  i:=st;
  ss:=0;
  while nr[i]<>L do
    begin
      ss:=ss+v[i];
      i:=i+1;
    end;
  volumL:=v[i];
  sd:=0;
  for j:=i+1 to dr do
    sd:=sd+v[j];
  total:=ss+sd+volumL;
  jumatate:=total div 2;
  writeln(g,jumatate);
  if ss<jumatate then
    if ss+volumL<=jumatate then
      begin
        writeln(g,jumatate-ss,' S');
        writeln(g,jumatate-ss-volumL,' S');
      end
    else
      begin
        writeln(g,jumatate-ss,' S');
        writeln(g,jumatate-sd,' D');
      end
  else
    if sd+v[L]<=jumatate then
      begin
        writeln(g,jumatate-sd,' D');
        writeln(g,jumatate-sd-volumL,' D');
      end
    else
      begin
        writeln(g,jumatate-sd,' D');
        writeln(g,jumatate-ss,' S');
      end;
  close(f);
  close(g);
end.
