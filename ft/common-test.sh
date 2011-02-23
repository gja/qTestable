SERVER=org.qTestable.FT
./`basename $PWD` --enable-qTestable &
CHILDPID=$!

function wait_for_start()
{
  TRIES=0
  while [ "`qdbus $SERVER / org.qTestable.IsEnabled`" != "true" ]; do
    sleep 0.1
    TRIES=$((TRIES+1))
    if [ "$TRIES" -gt 150 ]; then
      echo "Unable to connect";
      exit -1
    fi
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
