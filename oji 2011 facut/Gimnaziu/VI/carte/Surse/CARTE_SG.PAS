
var a:array[1..10000] of integer;
    f,g:text;
    i,x,max,n,pagini,zile,ziua:integer;
begin
     assign(f,'carte.in');reset(f);
     assign(g,'carte.out');rewrite(g);
     read(f,n);
     for i:=1 to n do read(f,a[i]);
     x:=0;
     max:=0;
     repeat
           pagini:=0;
           inc(zile);
           for i:=1 to n do
               if a[i]=x+1 then begin
                  x:=x+1;
                  inc(pagini)
               end;
           if pagini>max then begin
              max:=pagini;
              ziua:=zile
           end;
     until x=n;
     write(g,zile,' ',ziua,' ',max);
     close(g)
end.