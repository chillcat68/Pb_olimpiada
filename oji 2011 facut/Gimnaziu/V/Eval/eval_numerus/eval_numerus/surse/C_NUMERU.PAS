program numerus;
var f,g:text;
    n,k,i,l:longint;

begin
  assign(f,'numerus.in');
  reset(f);
  assign(g,'numerus.out');
  rewrite(g);
  readln(f,k,n);
  if k mod 2=1 then
    begin
      for i:=(k-1)*5+1 to k*5 do
        write(g,i,' ');
      writeln(g,5*k);

    end
  else
    begin
      write(g,5*k);
      for i:=k*5 downto (k-1)*5+1 do
        write(g,' ',i);
      writeln(g);
    end;

  if n mod 5=0 then
    begin
      l:=n div 5;
      writeln(g,l);
      if l mod 2=0 then
        writeln(g,'A B')
      else
        writeln(g,'E F');
    end
  else
    begin
      l:=n div 5+1;
      writeln(g,l);
      if l mod 2=0 then
        writeln(g,chr(ord('F')-n mod 5+1))
      else
        writeln(g,chr(ord('A')+n mod 5-1));
    end;
  close(f);
  close(g);
end.
