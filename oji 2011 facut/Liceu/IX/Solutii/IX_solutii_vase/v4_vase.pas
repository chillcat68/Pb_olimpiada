{prof.Zoltan Szabo - 100 p}
var v:array[1..100000] of longint;
    c:array[1..100000] of char;
    L,i,n:longint;
    f,g:text;
    jumatate,total,ss,sd:int64;
begin
  assign(f,'vase.in');
  reset(f);
  assign(g,'vase.out');
  rewrite(g);
  readln(f,n);
  for i:=1 to n do
    begin
      readln(f,v[i],c[i],c[i]);
    end;
  readln(f,L);
  ss:=0;
  sd:=0;
  if c[L]='S' then
    begin
      for i:=1 to L-1 do
        sd:=sd+v[i];
      for i:=L+1 to n do
        if c[i]='S' then
          ss:=ss+v[i]
        else
          sd:=sd+v[i];
    end
  else
    begin
      for i:=1 to L-1 do
        ss:=ss+v[i];
      for i:=L+1 to n do
        if c[i]='S' then
          ss:=ss+v[i]
        else
          sd:=sd+v[i];
    end;
  total:=ss+sd+v[L];
  jumatate:=total div 2;
  writeln(g,jumatate);
  if ss<jumatate then
    if ss+v[L]<=jumatate then
      begin
        writeln(g,jumatate-ss,' S');
        writeln(g,jumatate-ss-v[L],' S');
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
        writeln(g,jumatate-sd-v[L],' D');
      end
    else
      begin
        writeln(g,jumatate-sd,' D');
        writeln(g,jumatate-ss,' S');
      end;
  close(f);
  close(g);
end.
