{Problema 2sah - solutia oficiala O(logN N)}

const modulo=100003;
type mat=array [1..3,1..3] of int64;
var f,g:text;
    t,n,k:int64;
    a,s,c:mat;

procedure sol1();
  var ans, p:int64;
  begin
    ans:=1; p:=3;
    k:=k-1;
    while (k<>0) do
       begin
         if k mod 2 = 1 then ans:=(ans*p) mod modulo;
         p:=(p*p) mod modulo;
         k:=k shr 1;
       end;
    write(g,ans);
  end;

procedure sol2();
  var i,j,q:byte;
  begin
    k:=n+2-k;
    for i:=1 to 3 do
      begin
        s[i,i]:=1;
        a[3,i]:=1;
      end;
    a[1,2]:=1;
    a[2,3]:=1;
    while (k<>0) do
      begin
        if k mod 2 = 1 then
          begin
            for i:=1 to 3 do
              for j:=1 to 3 do
                begin
                  c[i,j]:=0;
                  for q:=1 to 3 do
                    c[i,j]:=(c[i,j]+s[i,q]*a[q,j]) mod modulo;
                end;
            for i:=1 to 3 do
              for j:=1 to 3 do
                s[i,j]:=c[i,j];
          end;
        for i:=1 to 3 do
          for j:=1 to 3 do
            begin
              c[i,j]:=0;
              for q:=1 to 3 do
                c[i,j]:=(c[i,j]+a[i,q]*a[q,j]) mod modulo;
            end;
        for i:=1 to 3 do
          for j:=1 to 3 do
            a[i,j]:=c[i,j];
        k:=k shr 1;
      end;
    write(g,s[2,3]);
  end;

  begin
    assign(f,'2sah.in');
    assign(g,'2sah.out');
    reset(f); rewrite(g);
    read(f,t,n,k);
    close(f);
    if t=1 then sol1
           else sol2;
    close(g);
  end.
