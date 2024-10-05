var a,b:array[1..10000] of integer;
    f,g:text;
    i,n,k,aux,grad,max,start,p,gr:integer;
    ordonat:boolean;
begin
     assign(f,'grad.in');reset(f);
     assign(g,'grad.out');rewrite(g);
     read(f,n,k);
     for i:=1 to n do read(f,a[i]);
     b:=a;
     repeat
           ordonat:=true;
           for i:=1 to n-1 do
            if b[i]>b[i+1] then begin
               aux:=b[i];b[i]:=b[i+1];b[i+1]:=aux;
               ordonat:=false
            end;
     until ordonat;
     grad:=0;
     for i:=1 to n do
         if a[i]=b[i] then inc(grad);
     writeln(g,grad);
     max:=0;
     for p:=1 to n-k+1 do begin
         gr:=0;
         b:=a;
         repeat
               ordonat:=true;
               for i:=p to p+k-2 do
                if b[i]>b[i+1] then begin
                    aux:=b[i];b[i]:=b[i+1];b[i+1]:=aux;
                    ordonat:=false
                end;
         until ordonat;
         for i:=p to p+k-1 do
             if a[i]=b[i] then inc(gr);
         if gr>max then begin
            max:=gr;start:=p
         end;
     end;
     write(g,start,' ',max);
     close(g)
end.