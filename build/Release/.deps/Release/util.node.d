cmd_Release/util.node := ln -f "Release/obj.target/util.node" "Release/util.node" 2>/dev/null || (rm -rf "Release/util.node" && cp -af "Release/obj.target/util.node" "Release/util.node")
