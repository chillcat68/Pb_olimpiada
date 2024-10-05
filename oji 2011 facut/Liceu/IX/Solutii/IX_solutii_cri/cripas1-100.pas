{prof. Zoltan Szabo - solutie problema cri - implementare cu tablou bidimensional}

var f,g:text;
    zonamax,n,m,x,y,i,j:integer;
    a:array[1..500,1..500] of longint;
    min,cantmax,cameremin,s:longint;
begin
  assign(f,'cri.in');
  reset(f);
  assign(g,'cri.out');
  rewrite(g);
  readln(f,n,m,x,y);

  for i:=1 to n do
    for j:=1 to m do
      read(f,a[i,j]);
  zonamax:=0;cantmax:=0;cameremin:=0;
  s:=0;                    {suma grauntelor in prima zona}
  for i:=1 to x do
    for j:=1 to y do
      s:=s+a[i,j];
  if odd(x) or odd(y) then
    begin
      zonamax:=1;          {daca avem o dimensiune impara toate grauntele}
      cantmax:=s;              {se vor strange}
      cameremin:=x*y;
    end
  else
    begin
      min:=100000000;        {daca dimensiunile camerei sunt par*par}
      for i:=1 to x do  {pozitia impara cu numar minim de graunte se va ocoli}
        for j:=1 to y do
          if odd(i+j) and (a[i,j]<min) then
            min:=a[i,j];
      zonamax:=1;
      cantmax:=s-min;
      cameremin:=x*y-1;
    end;

  s:=0;                    {suma grauntelor in zona a 2-a}
  for i:=1 to x do
    for j:=y to m do
      s:=s+a[i,j];
  if odd(x) or odd(m-y+1) then
    begin
      if (s>cantmax) or ((s=cantmax) and (cameremin>x*(m-y+1))) then
        begin
          zonamax:=2;          {daca avem o dimensiune impara toate grauntele}
          cantmax:=s;              {se vor strange}
          cameremin:=x*(m-y+1);
        end
    end
  else
    begin
      min:=100000000;        {daca dimensiunile camerei sunt par*par}
      for i:=1 to x do  {pozitia impara cu numar minim de graunte se va ocoli}
        for j:=y to m do
          if odd(i+j+1+m) and (a[i,j]<min) then
            min:=a[i,j];
      if (s-min>cantmax) or ((s-min=cantmax) and (cameremin>x*(m-y+1)-1)) then
        begin
          zonamax:=2;
          cantmax:=s-min;
          cameremin:=x*(m-y+1)-1;
        end;
    end;

  s:=0;                    {suma grauntelor in zona a 3-a}
  for i:=x to n do
    for j:=1 to y do
      s:=s+a[i,j];
  if odd(n-x+1) or odd(y) then
    begin
      if (s>cantmax) or ((s=cantmax) and (cameremin>(n-x+1)*y)) then 
        begin
          zonamax:=3;          {daca avem o dimensiune impara toate grauntele}
          cantmax:=s;              {se vor strange}
          cameremin:=(n-x+1)*y;
        end
    end
  else
    begin
      min:=100000000;        {daca dimensiunile camerei sunt par*par}
      for i:=x to n do  {pozitia impara cu numar minim de graunte se va ocoli}
        for j:=1 to y do
          if odd(i+j+1+n) and (a[i,j]<min) then
            min:=a[i,j];
      if (s-min>cantmax) or ((s-min=cantmax) and (cameremin>(n-x+1)*y-1)) then
        begin
          zonamax:=3;
          cantmax:=s-min;
          cameremin:=(n-x+1)*y-1;
        end;
    end;

  s:=0;                    {suma grauntelor in zona a 4-a}
  for i:=x to n do
    for j:=y to m do
      s:=s+a[i,j];
  if odd(n-x+1) or odd(m-y+1) then
    begin
      if (s>cantmax) or ((s=cantmax) and (cameremin>(n-x+1)*(m-y+1))) then
        begin
          zonamax:=4;          {daca avem o dimensiune impara toate grauntele}
          cantmax:=s;              {se vor strange}
          cameremin:=(n-x+1)*(m-y+1);
        end
    end
  else
    begin
      min:=100000000;        {daca dimensiunile camerei sunt par*par}
      for i:=x to n do  {pozitia impara cu numar minim de graunte se va ocoli}
        for j:=y to m do
          if odd(i+j+m+n) and (a[i,j]<min) then 
            min:=a[i,j];
      if (s-min>cantmax) or ((s-min=cantmax) and (cameremin>(n-x+1)*(m-y+1)-1)) then
        begin
          zonamax:=4;
          cantmax:=s-min;
          cameremin:=(n-x+1)*(m-y+1)-1;
        end;
    end;

  writeln(g,zonamax,' ',cantmax,' ',cameremin);
  close(f);
  close(g);
end.
