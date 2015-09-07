########################################################################
# input file
target = './tokutoku.csv'
# output filename prefix
output = './comeback_150406_'
# output filename saffix
ext = '.csv'
# cut sizee
cut_size = 30000
########################################################################
open(target) {|file|
    filenum = 0
    linenum = 0
    out = File.open(output + filenum.to_s + ext,'w')
    while line = file.gets 
        out.puts line
        linenum += 1
        if(linenum >= cut_size)
            linenum = 0
            filenum += 1
            out.close
            out = File.open(output + filenum.to_s + ext,'w')
        end
    end
}
puts "end" 
