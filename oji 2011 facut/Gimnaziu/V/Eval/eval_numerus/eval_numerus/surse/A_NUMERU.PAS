var f,g:text;
    n,i,k,a,b,l,c:longint;

begin
   assign(f,'numerus.in');
   reset(f);
   assign( g,'numerus.out');
   rewrite(g);
   read(f,k,n);
   a:=5*(k-1)+1;b:=5*k;
   if k mod 2=1 then
   begin
     for i:=a to b do write(g,i,' ');
     write(g,b);
   end
   else
   begin
     write(g,b,' ');
     for i:=b downto a do write(g,i,' ');
   end;
   writeln(g);
   l:=n div 5;
   if n mod 5>0 then inc(l);
   writeln(g,l);
   if n mod 5=0 then
      if l mod 2=0 then writeln(g,'A',' ','B')
      else writeln(g,'E',' ','F')
   else
      if l mod 2=1 then writeln(g,chr(65+ n mod 5-1))
      else writeln(g,chr(70-n mod 5+1));
   close(f);
   close(g);
end.
