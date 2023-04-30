DELETE FROM `conditions` WHERE SourceTypeOrReferenceId = 15 AND SourceGroup = 16863;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
('15', '16863', '0', '0', '0', '9', '0', '34398', '0', '0', '0', '0', '', NULL),
('15', '16863', '0', '0', '1', '9', '0', '36881', '0', '0', '0', '0', '', NULL);

--
REPLACE INTO `spell_target_position` (`id`, `target_map`, `target_position_x`, `target_position_y`, `target_position_z`, `target_orientation`) VALUES 
('167771', '1265', '4066.5', '-2382.25', '94.8536', '1.570796');

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=78423;
DELETE FROM smart_scripts WHERE entryorguid = 78423;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(78423, 0, 0, 0, 62, 0, 100, 0, 16863, 0, 0, 0, 11, 168956, 18, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'At gossip select cast movie'),
(78423, 0, 1, 0, 62, 0, 100, 0, 16863, 0, 0, 0, 11, 167771, 18, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'At gossip select cast teleportation');