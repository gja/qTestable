#! /bin/sh

SERVER=org.qTestable.FT2
./02_button_with_slot_based_commands --enable-qTestable &
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

send_signal blah/button/click
send_signal blah/label/getText clicked
send_signal blah/app/quit
