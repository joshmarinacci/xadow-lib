//node.js required

var fs = require('fs');
var PNG = require('pngjs').PNG;
fs.createReadStream(process.argv[2])
    .pipe(new PNG({filterType:4}))
    .on('parsed',function() {
        var iw = this.width;
        var ih = this.height;
        if(ih%8 != 0) {
            console.log("ERROR: height not a multiple of 8");
            return;
        }
        
        console.log("static const int bmp_width = "+iw+";");
        console.log("static const int bmp_height = "+ih+";");
        
        console.log("static unsigned char NumberFont[]={");
        for(var y=0; y<ih; y+=8) {
            var str = "";
            for(var x=0; x<iw; x++) {
                var val = 0;
                for(var yy=7; yy>=0; yy--) {
                    var i = (this.width*(y+yy)+x)*4;
                    var r  = this.data[i+0];
                    var g  = this.data[i+1];
                    var b  = this.data[i+2];
                    var a  = this.data[i+3];
                    var c = (r+g+b)/3;
                    var on = (c<180);
                    val = val << 1;
                    if(on) {
                        val += 1;
                    }
                }
                str += ('0x'+val.toString(16)+',');
            }
            console.log(str);
        }
        console.log("};");
    });
    
