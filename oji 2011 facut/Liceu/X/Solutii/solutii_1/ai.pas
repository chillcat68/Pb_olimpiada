{ Stelian Ciurea }
type
    pozitii = array[0..1000] of integer;

var fi,fo:text;
    a   :array[0..1001,0..1001] of byte;
    opt :array[0..1001,0..1001] of longint;
    qx,qy : array[1..1000001] of integer;
    min11,min12,min21,min22,n,i,j,lmax,lc,k,x:longint;
    pozx1,pozy2,pozx2,pozy1:pozitii;
    pozi,pozj,dir,sx1,sy1,sx2,sy2,rx1,ry1,rx2,ry2,tx,ty : integer;
    dtsx1,dtsx2,dtsy1,dtsy2,dx1,dx2,dy1,dy2,k1,k2 : integer;
const
    depx : array[1..4] of integer = ( 1, 0,-1, 0);
    depy : array[1..4] of integer = ( 0, 1,-0,-1);
function sign(x:integer):integer;
begin
  if x>0 then sign := 1
   else
    if x<0 then sign:=-1
     else sign := 0
  end;

function max(a,b:longint):longint;
begin
  if a>b then max := a else max := b
end;

procedure writemata;
var i,j:integer;
begin
  for i := 0 to n+1 do
    begin
      for j := 0 to n+1 do
        write(a[i][j]:4);
      writeln
    end;
    writeln
  end;

procedure writemato;
var i,j:integer;
begin
  for i := 0 to n+1 do
    begin
      for j := 0 to n+1 do
        write(opt[i][j]:4);
      writeln
    end;
    writeln
  end;


procedure calcpoz(x,y : integer; var pozx,pozy : pozitii; var nr:integer);
var i,j,k,dx,dy,dx1,dy1:integer;
begin
  nr := 0;
  if tx = x then
   begin
    if y < ty then
     begin
        for j := y to ty-1 do
        if a[x][j]=0 then
          begin
            inc(nr); pozx[nr] := x; pozy[nr] := j
          end
     end
    else
     for j := ty+1 to y do
      if a[x][j]=0 then
          begin
            inc(nr); pozx[nr] := x; pozy[nr] := j
          end;
    exit
   end;
  if ty = y then
   begin
    if x < tx then
        for i := x to tx-1 do
         if a[i][y]=0 then
          begin
            inc(nr); pozx[nr] := i; pozy[nr] := y
          end
         else
    else
     for i := tx+1 to x do
      if a[i][y]=0 then
          begin
            inc(nr); pozx[nr] := i; pozy[nr] := y
          end ;
    exit
   end;

   nr := 1;
   pozx[1]:=x; pozy[1]:=y;
   dx := tx - x; dy := ty - y;
   for i := 1 to n do
     for j := 1 to n do
       begin
         dx1 := i - x;
         dy1 := j - y;
        // writeln(i,' ',j,' ',dx,' ',dy,' ',dx1,' ',dy1);
         if dx*dy1 = dy*dx1 then
          if a[i][j]=0 then
           if (sign(dx)=sign(dx1)) and (sign(dy)=sign(dy1)) then
           if (tx<i) and (i<x) or (tx>i) and (i>x) then
           begin
            inc(nr); pozx[nr] := i; pozy[nr] := j;
           end;
       end;
end;


procedure Lee(xs,ys:integer);
var first,last,i,j,z,xc,yc,xv,yv : longint;
begin
 for i := 1 to n do
   for j := 1 to n do
    opt[i][j] := n*n+1;
 first:=1;last:=2;
 qx[first] := xs;
 qy[first] := ys;
 opt[xs,ys] := 0;
 while first<last do
   begin
    xc := qx[first];
    yc := qy[first];
//    writeln(xc,' ',yc);
    inc(first);
    for z := 1 to 4 do
      begin
       xv := xc + depx[z];
       yv := yc + depy[z];
 //      writeln('  ',xv,' ',yv);
       if a[xv][yv]=0 then
        if opt[xv][yv]>opt[xc][yc]+1 then
          begin
            opt[xv][yv] := opt[xc][yc]+1;
            qx[last] := xv;
            qy[last] := yv;
            inc(last);
          end;
       end;
   end;
end;



begin
  assign(fi,'ai.in');  reset(fi);
  assign(fo,'ai.out'); rewrite(fo);
  readln(fi,n);
  readln(fi,tx,ty,sx1,sy1,sx2,sy2,rx1,ry1,rx2,ry2);
  a[tx,ty] := 2;
  readln(fi,k);
  for x := 1 to k do
   begin
    read(fi,i,j);
    a[i][j] := 1;
   end;

  lmax := 0;
  for i := 1 to n do
  begin
    lc := 0;
    for j := 1 to n do
    begin
      if a[i][j]=1 then
        inc(lc)
       else lc := 0;
      if lc > lmax then
      begin
        lmax := lc;
        pozi:=i;
        pozj:=j;
        dir:=1;
      end;
    end;
  end;
  for j := 1 to n do
   begin
    lc := 0;
    for i := 1 to n do
     begin
      if a[i][j]=1 then
        inc(lc)
      else lc := 0;
     if lc > lmax then
      begin
        lmax := lc ;
        pozi:=i;
        pozj:=j;
        dir:=2;
      end;

     end
    end;
   writeln('lmax=',lmax);
   writeln;

   calcpoz(sx1,sy1,pozx1,pozy1,k1);
//     for i := 1 to k1 do write(pozx1[i],' ',pozy1[i],'   ');  writeln;
   calcpoz(sx2,sy2,pozx2,pozy2,k2);
//     for i := 1 to k2 do write(pozx2[i],' ',pozy2[i],'   ');

//     writeln;
//     writeln(k1,' ',k2);

     for i := 0 to n+1 do
      begin
        a[i][0] := 1;
        a[0][i] := 1;
        a[n+1][i] := 0;
        a[i][n+1] := 1;
      end;


//   writemata;

   Lee(rx1,ry1);

//   writemato;

   min11 := n*n+2;
   min12 := min11;
   for k := 1 to k1 do
     begin
       i := pozx1[k];
       j := pozy1[k];
       if opt[i][j]<min11 then
         min11 := opt[i][j];
     end;
   for k := 1 to k2 do
     begin
       i := pozx2[k];
       j := pozy2[k];
       if opt[i][j]<min12 then
         min12 := opt[i][j];
     end;

   Lee(rx2,ry2);

   min21 := n*n+2;
   min22 := min21;
   for k := 1 to k1 do
     begin
       i := pozx1[k];
       j := pozy1[k];
       if opt[i][j]<min21 then
         min21 := opt[i][j];
     end;
   for k := 1 to k2 do
     begin
       i := pozx2[k];
       j := pozy2[k];
       if opt[i][j]<min22 then
         min22 := opt[i][j];
     end;


   writeln(min11,' ',min12);
   writeln(min21,' ',min22);

   if max(min11,min22) < max(min12,min21) then
    writeln(max(min11,min22))
    else
      writeln(max(min21,min12));

   writeln(fo,lmax);
   if max(min11,min22) < max(min12,min21) then
    writeln(fo,max(min11,min22))
    else
      writeln(fo,max(min21,min12));

   close(fo);
//   readln
  end.
