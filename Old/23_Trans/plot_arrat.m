arr=cat(3,[.47,0.01,0.01; .98,.38,.01;.98,.67,.38],[.81,.12,0.01;.99,.80,.65;.999,.88,.79],[.93,.61,.42;.999,.91,.85;.999,.95,.89]);
x=arr(:,:,1);
y=arr(:,:,2);
z=arr(:,:,3);
plot3(x,y,z,'.-')