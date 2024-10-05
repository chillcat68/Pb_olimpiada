var f,g:text;
    n,i,cif,nrc:integer;
    c,sp:char;
    vc:array[0..9] of byte;

begin
     assign(f,'magic.in');
     assign(g,'magic.out');
     reset(f);
     rewrite(g);
     readln(f,n);
     for i:=1 to n do
     begin
        read(f,c,sp);
        if (c>='a') and (c<='z') then
           write(g,char(ord(c)-32))
        else
           vc[ord(c)-48]:=1;
     end;
     writeln(g);
     if vc[0]<>0 then
     begin
          i:=1;
          while (vc[i]=0) and (i<=9) do inc(i);
     end;
     if i<=9 then
     begin
          write(g,i);vc[i]:=0;
     end;
     for i:=0 to 9 do
       if vc[i]>0 then begin write(g,i); inc(nrc); end;
     if nrc=0 then writeln(f,'NU EXISTA');
     close(f);
     close(g);
end.