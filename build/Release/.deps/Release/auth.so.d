cmd_Release/auth.so := ln -f "Release/obj.target/auth.so" "Release/auth.so" 2>/dev/null || (rm -rf "Release/auth.so" && cp -af "Release/obj.target/auth.so" "Release/auth.so")
