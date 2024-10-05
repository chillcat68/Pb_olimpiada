{Dana Lica - 100 puncte}
{operatii pe biti}

var s1,s2,i,j,n,m:longint;
    a:array[1..25]of byte;
    ok:boolean;

begin
   assign(input,'adunscad.in');reset(input);
   assign(output,'adunscad.out');rewrite(output);
   readln(N,M);
   for i:=1 to M do read(a[i]);
   ok:=false;
   for i:=0 to 1 shl(M-1) do begin
     s1:=0; s2:=0;
     for j:=0 to M-1 do
      if i shr j and 1 = 1 then begin inc(s1,a[j+1]); dec(s2,a[j+1]); end
                           else begin inc(s2,a[j+1]); dec(s1,a[j+1]); end;
      if s1=N then begin
          for j:=0 to M-1 do
             if i shr j and 1 = 1 then
              if j=0 then write(a[j+1]) else write('+',a[j+1])
             else write ('-',a[j+1]);
          ok:=true;
          break;
      end;
      if s2=N then begin
          for j:=0 to M-1 do
             if i shr j and 1 = 0 then
              if j=0 then write(a[j+1]) else write('+',a[j+1])
             else write ('-',a[j+1]);
          ok:=true;
          break;
      end;
   end;
   if not ok then writeln('0')
   else writeln;
   close(output);
end.