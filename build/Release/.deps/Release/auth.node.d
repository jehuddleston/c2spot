cmd_Release/auth.node := ln -f "Release/obj.target/auth.node" "Release/auth.node" 2>/dev/null || (rm -rf "Release/auth.node" && cp -af "Release/obj.target/auth.node" "Release/auth.node")
