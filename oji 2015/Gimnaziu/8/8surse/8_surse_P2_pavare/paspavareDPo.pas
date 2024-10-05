program pavare;
var i,n,k,c,t,p,z:longint;
f,g:text;
Begin
 assign(f,'pavare.in');reset(f);
 assign(g,'pavare.out');rewrite(g);
 read(f,c,n);
 k:=trunc(2*sqrt(n))-1;
 if sqrt(n)<>trunc(sqrt(n)) then k:=k+1;
 if c=1 then writeln(g,k)
  else
   begin
    z:=1;
    t:=1;
    p:=((k+k mod 2) div 2)*((k+k mod 2) div 2 + 1 - k mod 2);
    for i:=1 to k do
     begin
       if (i>=(k div 2 + n- p+1 + k mod 2))and(i<=k div 2 + k mod 2) then write(g,z-1,' ')
         else write(g,z,' ');
       if i>=(k div 2 + k mod 2) then t:=-1;
       if (i=k div 2)and(k mod 2 =0) then t:=0;
       z:=z+t;
     end;
   end;
  close(f);
  close(g);
End.
