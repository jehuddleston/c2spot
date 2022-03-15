cmd_Release/c2spot.node := ln -f "Release/obj.target/c2spot.node" "Release/c2spot.node" 2>/dev/null || (rm -rf "Release/c2spot.node" && cp -af "Release/obj.target/c2spot.node" "Release/c2spot.node")
