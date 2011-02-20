#! /bin/sh

SERVER=org.qTestable.FT1

./01_a_simple_button --enable-qTestable &
CHILDPID=$!

sleep 0.25

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

send_signal blah/button/click
send_signal blah/label/getText clicked
send_signal blah/app/quit
