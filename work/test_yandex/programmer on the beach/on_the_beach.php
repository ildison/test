#!/usr/bin/php
<?php

function getMinDissimilarity($sunbeds, $count_sunbed)
{
	$minDiss = PHP_INT_MAX;
	for ($i = 0; $i < $count_sunbed - 1; ++$i)
	{
		for ($j = $i + 1; $j < $count_sunbed; ++$j)
		{
			$diss = (int)$sunbeds[$i] ^ (int)$sunbeds[$j];
			if ($diss < $minDiss)
				$minDiss = $diss;
		}
	}
	return ($minDiss);
}

$dissimilarity = array();
$count_tests = (int)fgets(STDIN);
while ($count_tests)
{
	$count_sunbed = (int)fgets(STDIN);
	$sunbeds = preg_split("/[\s]+/", trim(fgets(STDIN)));
	$dissimilarity[] = getMinDissimilarity(sort($sunbeds), $count_sunbed);
	--$count_tests;
}
foreach($dissimilarity as $diss)
	echo $diss . PHP_EOL;

// for ($i = 0; $i < 30; ++$i)
// {
// 	echo ("10 xor " . $i . " = " . (21 ^ $i) . PHP_EOL);
// }

?>