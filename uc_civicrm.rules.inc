<?php

/**
 * @file
 * This file contains the Rules hooks and functions necessary to make the order
 * related entity, conditions, events, and actions work.
 */
function uc_civicrm_rules_action_info_alter(&$actions) {
  $order_arg = array(
    'type' => 'uc_order',
    'label' => t('Order'),
  );

  $actions['uc_order_update_status'] = array(
    'label' => t('Update the order status and sync with CiviCRM'),
    'group' => t('Order'),
    'base' => 'uc_civicrm_syncronize_status',
    'parameter' => array(
      'order' => $order_arg,
      'order_status' => array(
        'type' => 'text',
        'label' => t('Status'),
        'options list' => 'uc_order_action_update_status_options',
      ),
    ),
  );
}

/*
function  uc_civicrm_rules_data_info() {
  return array(
    'node' => array(
      'label' => t('content'), 
      'parent' => 'entity', 
      'group' => t('Node'),
    ),
    // Formatted text as used by in hook_entity_property_info() for text fields. 
    'text_formatted' => array(
      'label' => t('formatted text'), 
      'ui class' => 'RulesDataUITextFormatted', 
      'wrap' => TRUE, 
      'property info' => entity_property_text_formatted_info(),
    ),
  );
}

function uc_civicrm_rules_event_info() {
  $events['uc_order_status_update'] = array(
    'label' => t('Ubercart oder is submitted'),
    'group' => t('Ubercart CiviCRM Integrator'),
    'variables' => array(
      'order' => array(
        'type' => 'uc_order',
        'label' => t('Original order'),
      ),
      'updated_order' => array(
        'type' => 'uc_order',
        'label' => t('Updated order'),
      ),
    ),
  );

  return $events;
}
function uc_civicrm_rules_action_info() {
  return array(
    'sync_with_civicrm' => array(
      'label' => t('Sync the order with CiviCRM'), 
      'parameter' => array(
        'user' => array(
          'type' => 'user',
          'label' => t('Customer'),
        ),
      ), 
      'group' => t('System'), 
      'base' => 'rules_action_mail_user', 
      'callbacks' => array(
        'validate' => 'rules_action_custom_validation', 
        'help' => 'rules_mail_help',
      ),
    ),
  );
}


/**
 *  Implementation of Ubercart conditional action hook_ca_predicate
 *
 *  Tell Ubercart to let us know when an order is complete
 *
function uc_civicrm_ca_predicate() {
  if (!module_exists('civicrm')) { return; }

  $predicates['uc_civicrm_contact_on_order'] = array(
    '#title'   => t('Copy to CiviCRM upon order submission'),
    '#trigger' => 'uc_checkout_complete',
    '#class'   => 'uc_civicrm',
    '#status'  => 1,
    '#actions' => array(
      array(
        '#name'         => 'uc_civicrm_order_to_civicrm',
        '#title'        => t('Copy order information to CiviCRM'),
        '#argument_map' => array(
          'order'       => 'order',
        ),
      ),
    ),
  );

  $predicates['uc_civicrm_check_order_status'] = array(
    '#title'   => t('Sync CiviCRM status on status update'),
    '#trigger' => 'uc_order_status_update',
    '#class'   => 'uc_civicrm',
    '#status'  => 1,
    '#actions' => array(
      array(
        '#name'         => 'uc_civicrm_sync_status',
        '#title'        => t('Syncronize status'),
        '#argument_map' => array(
          'order'       => 'updated_order',
        ),
      ),
    ),
  );

  return $predicates;
}
*/
