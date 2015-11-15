{
    "targets": [
        {
            "target_name": "Uname2",
            "sources": [ "uname2.cc", "functions.cc" ],
            "include_dirs" : [
 	 			"<!(node -e \"require('nan')\")"
			]
        }
    ],
}