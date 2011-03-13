SERVER="org.qTestable.FT"

def send_signal(signal, expected = nil)
  actual=`qdbus #{SERVER} / org.qTestable.Automate #{signal}`

  return actual if not expected

  if(actual != expected)
    send_signal 'application/quit/app'
    raise "Expected: #{expected}, Actual: #{actual}"
  end

  actual
end
