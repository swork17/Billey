xterm -title "Server" -hold -e "./bin/Server server1 4245" &
xterm -title "Client 1" -hold -e "./bin/Client 4245 1" &
xterm -title "Client 2" -hold -e "./bin/Client 4245 2" &
xterm -title "Client 3" -hold -e "./bin/Client 4245 3" &
xterm -title "Client 4" -hold -e "./bin/Client 4245 4" &