#! /bin/bash

SERVER=org.qTestable.FT
./install_smoke --enable-qTestable &
CHILDPID=$!

function wait_for_start()
{
  while [ "`qdbus $SERVER / org.qTestable.IsEnabled`" != "true" ]; do
    echo "sleep"
    sleep 0.1
  done
}

function send_signal()
{
  EXPECTED=$2
  ACTUAL=`qdbus $SERVER / org.qTestable.Automate $1`

  if [ "$EXPECTED" != "" -a "$ACTUAL" != "$EXPECTED" ]; then
    echo Expected: $EXPECTED, Actual: $ACTUAL
    kill $CHILDPID
    exit 1
  fi
}

wait_for_start

send_signal button/click/button
send_signal label/text/label clicked
send_signal application/quit/app
