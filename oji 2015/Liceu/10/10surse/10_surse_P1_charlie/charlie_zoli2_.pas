{
	Sursa 100p - stiva
	prof. Zoltan Szabo
	isj. Mures
}
var cuv,st:array[1..100001] of char;
    f,g:text;
    k,i,p,cost:longint;
function lungmax:longint;
var lung,max:longint;


begin
  max:=0;
  lung:=1;
  i:=1;
  while (i<k) do
    begin
      if (cuv[i]>cuv[i+1]) then
        begin
          lung:=1;
          p:=i;
          while (p<=k-2) and (cuv[p]>cuv[p+1]) and (cuv[p+1]<cuv[p+2]) do
            inc(p,2);
          inc(lung,p-i);
          if (lung>max) then
            max:=lung;
          i:=p+1;
        end
      else
        inc(i);
    end;
  lungmax:=max;
end;

function maxim(a,b:integer):integer;
begin
  if a>b then
    maxim:=a
  else
    maxim:=b;
end;

begin
  assign(f,'charlie.in');
  assign(g,'charlie.out');
  reset(f);
  rewrite(g);
  readln(f,p);
  k:=0;
  while not seekeof(f) do
  begin
    inc(k);
    read(f,cuv[k]);
  end;
  if p=1 then
    writeln(g,lungmax)
  else
    begin
      st[1]:=cuv[1];
      st[2]:=cuv[2];
      p:=2;
      cost:=0;
      for i:=3 to k do
        begin
          inc(p);
          st[p]:=cuv[i];
          while(p>=3) and (st[p-2]>st[p-1]) and (st[p-1]<st[p]) do
            begin
              cost:=cost+maxim(ord(st[p-2])-ord('a'),ord(st[p])-ord('a'))+1;
              dec(p);
              st[p]:=st[p+1];
            end;
        end;


      for i:=1 to p do
        write(g,st[i]);
      writeln(g);
      writeln(g,cost);
    end;
  close(f);
  close(g);
end.
