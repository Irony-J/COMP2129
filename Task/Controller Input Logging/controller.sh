#/bin/bash
socat pty,raw,echo=0,link=./controller0 pty,raw,echo=0,link=./device0 &
#socat pipe:./controller0 pipe:./device0 &
echo $! > socat_pid
sleep 1
./controller
kill -INT $(cat socat_pid)
rm socat_pid

