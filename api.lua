
local lastPressTime = os.clock();
print(lastPressTime)
while true do
    sleep(0.05)
    if redstone.getInput("back") then
        print("Requesting Get from IP")
        print(http.get("http://192.168.15.4:3000/beep"))
        os.pullEvent("redstone")
    end

end
