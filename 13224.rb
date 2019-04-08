r=1
gets.chomp.chars.each{|i|r=i=='A'?(r==1?2:r==2?1:r):i=='B'?(r==2?3:r==3?2:r):(r==1?3:r==3?1:r)}
puts r
