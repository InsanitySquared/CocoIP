# CocoIP
A quick and easy way to transfer data over the internet between any two devices.

It is a API that transforms the lengthy process of socket handling into a succinct operation that allows more time for endevours of a higher caliber and frees up resources.

There is still much work to do but core functionality is up to par.

# Important Note:
As of now, only the windows client library and the linux server library is on this repo. We are still working on the windows server and linux client.

# Use cases:
client(device eg rover) <-> Server <-> client(controller ie a computer running a GUI control interface and can display telemetry)

client(device eg rover <-> Server (server linked to controll gui so the server itself sends commands to rover)

server(device eg rover) <-> client controller to send commands to it (not recomended, TODO- why it isnt recomended)

# Documentation
A website is coming up soon. As of now, here is a basic example:

Tracking a GPS unit in real time via the internet:

First download the two files for each device, ie serverCon.h and serverCon.cpp for the client and include it in your code using #include"serverCon.h" (assuming they are in the same directry as the code you include in of course)

Do the same for the server code.

TODO- finish documentation here
