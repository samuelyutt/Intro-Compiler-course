//&S-
//&T-

invocation;

call(a, b: integer): integer;
begin
  if a < b then
    return 55146;
  else
    return 22146;
  end if
end
end call

begin
  call(20, 30);
  call(call(20, 30));
end
end invocation
