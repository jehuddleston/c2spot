cmd_Release/util.so := ln -f "Release/obj.target/util.so" "Release/util.so" 2>/dev/null || (rm -rf "Release/util.so" && cp -af "Release/obj.target/util.so" "Release/util.so")
