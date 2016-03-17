<?php

/**
 * @file
 * Features related hooks for bat_availability_constraints module.
 */

/**
 * Implements hook_features_pipe_COMPONENT_alter() for bat_unit_type component.
 */
function bat_availability_constraints_features_pipe_bat_unit_type_alter(&$pipe, $data, $export) {
  if (!empty($data)) {
    $variables = array(
      'bat_availability_constraints_unit',
      'bat_availability_constraints_type',
    );

    // Support the separate field base -vs- field instance structure that was
    // added in Features v7.x-2.0-beta2.
    if (function_exists('field_instance_features_export')) {
      $export_var = 'field_instance';
    }
    else {
      $export_var = 'field';
    }

    foreach ($data as $bat_unit_type) {
      foreach ($variables as $variable_name) {
        $pipe['variable'][] = "{$variable_name}_{$bat_unit_type}";
      }
      $pipe[$export_var][] = 'bat_unit_type-bat_unit_type-bat_constraints_range';
    }
  }
}